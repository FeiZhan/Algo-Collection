import React, { useEffect, useState } from 'react';
import DataChart from './DataChart';
import WorldMap from './WorldMap';
import ChartType from '../types/ChartType';
import DataType from '../types/DataType';
import FilterType from '../types/FilterType';
import { CircularProgress } from '@mui/material';

type DataDisplayProps = {
  filters: FilterType;
  onFilterChange: React.Dispatch<React.SetStateAction<FilterType>>;
};

const fetchData = async (
  filter: { country: string; startDate: string; endDate: string },
  setData: React.Dispatch<React.SetStateAction<DataType[]>>,
  setLoading: React.Dispatch<React.SetStateAction<boolean>>
) => {
  if (filter.country && filter.startDate && filter.endDate) {
    setLoading(true);
    try {
      const response = await fetch(
        `http://localhost:5000/api/covid?country=${filter.country}&startDate=${filter.startDate}&endDate=${filter.endDate}`
      );
      const data: DataType[] = await response.json();
      setData(data);
    } catch (error) {
      console.error('Failed to fetch data:', error);
      setData([]);
    } finally {
      setLoading(false);
    }
  }
};

export const DataDisplay: React.FC<DataDisplayProps> = ({
  filters,
  onFilterChange,
}) => {
  const [data1, setData1] = useState<DataType[]>([]);
  const [data2, setData2] = useState<DataType[]>([]);
  const [loading1, setLoading1] = useState(false);
  const [loading2, setLoading2] = useState(false);

  const { baselineFilter, comparisonFilter, chartType, column } = filters;

  useEffect(() => {
    fetchData(baselineFilter, setData1, setLoading1);
  }, [baselineFilter]);

  useEffect(() => {
    if (comparisonFilter) {
      fetchData(comparisonFilter, setData2, setLoading2);
    }
  }, [comparisonFilter]);

  const handleCountrySelect = (countryName: string) => {
    onFilterChange((prevFilters) => ({
      ...prevFilters,
      baselineFilter: { ...prevFilters.baselineFilter, country: countryName },
      chartType: ChartType.LINE,
    }));
  };

  return (loading1 || loading2) ? (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <CircularProgress />
      <p>Loading data for the selected country...</p>
    </div>
  ) : (
    <div
      className="chart-container"
      style={{
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center',
        padding: '20px',
      }}
    >
      {chartType === ChartType.MAP ? (
        <WorldMap
          endDate={baselineFilter.endDate}
          column={column}
          onCountrySelect={handleCountrySelect}
        />
      ) : (
        <DataChart
          data1={data1}
          data2={data2}
          chartType={chartType}
          selectedColumn={column}
        />
      )}
    </div>
  );
};

export default DataDisplay;
