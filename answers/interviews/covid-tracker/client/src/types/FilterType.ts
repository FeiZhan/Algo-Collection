import ChartType from './ChartType';
import ColumnType from './ColumnType';

type BaseFilterType = {
  country: string;
  startDate: string;
  endDate: string;
};

type Filter = {
  baselineFilter: BaseFilterType;
  comparisonFilter: BaseFilterType;
  chartType: ChartType;
  column: ColumnType;
};

export const defaultFilter: Filter = {
  baselineFilter: {
    country: 'Afghanistan',
    startDate: '2020-01-01',
    endDate: '2020-01-31',
  },
  comparisonFilter: {
    country: 'Afghanistan',
    startDate: '2020-01-01',
    endDate: '2020-01-31',
  },
  chartType: ChartType.LINE,
  column: ColumnType.total_cases,
};

export default Filter;
