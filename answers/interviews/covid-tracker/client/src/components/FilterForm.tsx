import React, { useState, useEffect, ChangeEvent } from 'react';
import { TextField, MenuItem, Select, FormControl, InputLabel, CircularProgress, Button, FormHelperText, Grid, SelectChangeEvent } from '@mui/material';
import DataType from '../types/DataType';

type FilterProps = {
  filters: {
    country: string;
    startDate: string;
    endDate: string;
  };
  onFilterSubmit: (newFilters: {
    country: string;
    startDate: string;
    endDate: string;
  }) => void;
};

const FilterForm: React.FC<FilterProps> = ({ filters, onFilterSubmit }) => {
  const [country, setCountry] = useState(filters.country);
  const [startDate, setStartDate] = useState(filters.startDate);
  const [endDate, setEndDate] = useState(filters.endDate);
  const [countries, setCountries] = useState<string[]>([]);
  const [loading, setLoading] = useState<boolean>(false);
  const [errorMessage, setErrorMessage] = useState<string>('');

  useEffect(() => {
    setCountry(filters.country);
    setStartDate(filters.startDate);
    setEndDate(filters.endDate);
  }, [filters]);

  useEffect(() => {
    const fetchCountries = async () => {
      try {
        setLoading(true);
        const response = await fetch(`http://localhost:5000/api/covid?column=location&endDate=2020-01-05`);
        if (!response.ok) {
          throw new Error('Error fetching countries');
        }
        const data = await response.json();
        const countrySet = new Set<string>(data.map((item: DataType) => item.location));
        setCountries(Array.from(countrySet));
      } catch (error) {
        console.error('Failed to fetch countries:', error);
      } finally {
        setLoading(false);
      }
    };

    fetchCountries();
  }, []);

  const validateDate = (date: string) => {
    return date && !isNaN(Date.parse(date));
  };

  const handleSubmit = () => {
    if (validateDate(startDate) && validateDate(endDate)) {
      setErrorMessage('');
      onFilterSubmit({ country, startDate, endDate });
    } else {
      setErrorMessage("Please enter valid start and end dates.");
    }
  };

  const handleCountryChange = (event: SelectChangeEvent<string>) => {
    setCountry(event.target.value);
  };

  const handleStartDateChange = (event: ChangeEvent<HTMLInputElement>) => {
    setStartDate(event.target.value);
  };

  const handleEndDateChange = (event: ChangeEvent<HTMLInputElement>) => {
    setEndDate(event.target.value);
  };

  const handleFormSubmit = (event: React.FormEvent) => {
    event.preventDefault();
    handleSubmit();
  };

  return (
    <form onSubmit={handleFormSubmit} className="filter-form">
      <Grid container spacing={0} alignItems="center">
        <Grid item xs={12} sm={4}>
          <FormControl fullWidth margin="normal" error={!!errorMessage}>
            <InputLabel>Country</InputLabel>
            <Select value={country} onChange={handleCountryChange} required>
              {loading ? (
                <MenuItem disabled>
                  <CircularProgress size={24} />
                </MenuItem>
              ) : countries.length === 0 ? (
                <MenuItem disabled>No countries available</MenuItem>
              ) : (
                countries.map((countryName) => (
                  <MenuItem key={countryName} value={countryName}>
                    {countryName}
                  </MenuItem>
                ))
              )}
            </Select>
            {errorMessage && <FormHelperText>{errorMessage}</FormHelperText>}
          </FormControl>
        </Grid>

        <Grid item xs={12} sm={3}>
          <TextField
            label="Start Date"
            type="date"
            value={startDate}
            onChange={handleStartDateChange}
            fullWidth
            InputLabelProps={{ shrink: true }}
            margin="normal"
            required
            error={!!errorMessage}
          />
        </Grid>

        <Grid item xs={12} sm={3}>
          <TextField
            label="End Date"
            type="date"
            value={endDate}
            onChange={handleEndDateChange}
            fullWidth
            InputLabelProps={{ shrink: true }}
            margin="normal"
            required
            error={!!errorMessage}
          />
        </Grid>

        <Grid item xs={6} sm={1}>
          <Button variant="contained" type="submit" color="primary" fullWidth>
            Submit
          </Button>
        </Grid>
      </Grid>
    </form>
  );
};

export default FilterForm;
