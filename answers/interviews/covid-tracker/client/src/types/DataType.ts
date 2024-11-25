import ColumnType from "./ColumnType";

type DataType = {
  [key in ColumnType]: string;
}

export default DataType;
