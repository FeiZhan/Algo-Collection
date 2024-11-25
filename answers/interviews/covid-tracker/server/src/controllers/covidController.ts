import fs from 'fs';
import path from 'path';
import csv from 'csv-parser';
import { Request, Response } from 'express';
import DataItem from '../types/dataItem';

const csvFilePath = path.join(__dirname, '../../../datasets/covid-19/public/data/owid-covid-data.csv');

let covidData: DataItem[] = [];

const loadCsvIntoMemory = async (): Promise<void> => {
  return new Promise<void>((resolve, reject) => {
    const data: DataItem[] = [];
    fs.createReadStream(csvFilePath)
      .pipe(csv())
      .on('data', (row: any) => {
        data.push(row);
      })
      .on('end', () => {
        covidData = data;
        console.log('CSV file loaded into memory.');
        resolve();
      })
      .on('error', (err: Error) => {
        console.error('Error loading CSV file:', err);
        reject(err);
      });
  });
};

export const getCovidData = (req: Request, res: Response): void => {
  const { country, startDate, endDate } = req.query;

  if (!covidData.length) {
    res.status(500).json({ message: 'Data not loaded into memory.' });
  }

  const filteredData = covidData.filter((row) => {
    const date = new Date(row.date);
    let include = true;

    if (country && row.location !== country) {
      include = false;
    }
    if (startDate && date < new Date(startDate as string)) {
      include = false;
    }
    if (endDate && date > new Date(endDate as string)) {
      include = false;
    }

    return include;
  });

  if (filteredData.length === 0) {
    res.status(404).json({ message: 'No data found for the given filters.' });
  }

  res.status(200).json(filteredData);
};

export const initializeCovidController = async (): Promise<void> => {
  await loadCsvIntoMemory();
};
