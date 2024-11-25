import React from 'react';
import { Box, FormControl, InputLabel, Select, MenuItem, Grid, SelectChangeEvent } from '@mui/material';
import FilterForm from './FilterForm';
import ChartType from '../types/ChartType';
import FilterType from '../types/FilterType';
import ColumnType from '../types/ColumnType';

type FilterPanelProps = {
  filters: FilterType;
  onFilterChange: (newFilters: FilterType) => void;
};

const FilterPanel: React.FC<FilterPanelProps> = ({ filters, onFilterChange }) => {
  const handleChartTypeChange = (event: SelectChangeEvent<ChartType>) => {
    onFilterChange({
      ...filters,
      chartType: event.target.value as ChartType,
    });
  };

  const handleColumnChange = (event: SelectChangeEvent<ColumnType>) => {
    onFilterChange({
      ...filters,
      column: event.target.value as ColumnType,
    });
  };

  const handleBaselineFilterChange = (newBaselineFilter: { country: string; startDate: string; endDate: string }) => {
    onFilterChange({
      ...filters,
      baselineFilter: newBaselineFilter,
    });
  };

  const handleComparisonFilterChange = (newComparisonFilter: { country: string; startDate: string; endDate: string }) => {
    onFilterChange({
      ...filters,
      comparisonFilter: newComparisonFilter,
    });
  };

  return (
    <Box sx={{ display: 'flex', justifyContent: 'center', alignItems: 'center', padding: 2 }}>
      <Grid container spacing={1} sx={{ maxWidth: 1200 }}>
        <Grid item xs={6} sm={2}>
          <FormControl fullWidth>
            <InputLabel id="chart-type-select-label">Chart Type</InputLabel>
            <Select
              labelId="chart-type-select-label"
              id="chart-type-select"
              value={filters.chartType}
              onChange={handleChartTypeChange}
              label="Chart Type"
            >
              {(Object.values(ChartType) as ChartType[]).map((chart) => (
                <MenuItem key={chart} value={chart}>
                  {chart}
                </MenuItem>
              ))}
            </Select>
          </FormControl>
        </Grid>

        <Grid item xs={6} sm={2}>
          <FormControl fullWidth sx={{ marginBottom: 2 }}>
            <InputLabel id="column-select-label">Select Column</InputLabel>
            <Select
              labelId="column-select-label"
              id="column-select"
              value={filters.column}
              onChange={handleColumnChange}
              label="Select Column"
            >
              {(Object.values(ColumnType) as ColumnType[]).map((column) => (
                <MenuItem key={column} value={column}>
                  {column}
                </MenuItem>
              ))}
            </Select>
          </FormControl>
        </Grid>

        <Grid item xs={12} sm={4}>
          <FilterForm
            filters={filters.baselineFilter ?? { country: '', startDate: '', endDate: '' }}
            onFilterSubmit={handleBaselineFilterChange}
          />
        </Grid>

        <Grid item xs={12} sm={4}>
          <FilterForm
            filters={filters.comparisonFilter ?? { country: '', startDate: '', endDate: '' }}
            onFilterSubmit={handleComparisonFilterChange}
          />
        </Grid>
      </Grid>
    </Box>
  );
};

export default FilterPanel;
