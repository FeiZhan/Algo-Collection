import csv
import json
import os

class DataProcessor:
    spec_dir = 'specs/'
    data_dir = 'data/'
    output_dir = 'output/'

    def __init__(self):
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    @classmethod
    def parse_spec(cls, file_name):
        spec_path = os.path.join(cls.spec_dir, file_name)
        spec = []
        with open(spec_path, mode = 'r') as file:
            reader = csv.DictReader(file)
            for row in reader:
                spec.append({
                    'column_name': row['column name'],
                    'width': int(row['width']),
                    'datatype': row['datatype']
                })

        return spec

    @classmethod
    def parse_data(cls, data_file, spec):
        data_path = os.path.join(cls.data_dir, data_file)
        output_file = os.path.join(cls.output_dir, data_file.replace('.txt', '.ndjson'))
        try:
            with open(data_path, mode = 'r') as input_file, open(output_file, mode = 'w') as output_file:
                for line in input_file:
                    if len(line) < sum(column['width'] for column in spec):
                        print(f"Error: Line does not match the expected width for file {data_file}.")
                        continue

                    json_object = {}
                    index = 0
                    for column in spec:
                        column_name = column['column_name']
                        data_type = column['datatype']
                        value = line[index : index + column['width']].strip()
                        index += column['width']
                        if data_type == 'TEXT':
                            json_object[column_name] = value
                        elif data_type == 'BOOLEAN':
                            if value == '1':
                                json_object[column_name] = True
                            elif value == '0':
                                json_object[column_name] = False
                            else:
                                print(f"Error: Invalid BOOLEAN value {value} for column {column_name}")
                                json_object[column_name] = None
                        elif data_type == 'INTEGER':
                            try:
                                json_object[column_name] = int(value)
                            except ValueError:
                                print(f"Error: Unable to convert {value} to INTEGER for column {column_name}")
                                json_object[column_name] = None
                    output_file.write(json.dumps(json_object) + '\n')
        except FileNotFoundError:
            print(f"Error: Data file {data_path} not found.")
        except OSError:
            print(f"Error: Could not read file {data_path}.")

    @classmethod
    def run(cls):
        for spec_file in os.listdir(cls.spec_dir):
            if spec_file.endswith('.csv'):
                spec = cls.parse_spec(spec_file)
                data_file_prefix = spec_file.replace('.csv', '')
                for data_file in os.listdir(cls.data_dir):
                    if data_file.startswith(data_file_prefix) and data_file.endswith('.txt'):
                        cls.parse_data(data_file, spec)

if __name__ == '__main__':
    processor = DataProcessor()
    processor.run()

'''
error handling:
    - spec directory is missing
    - spec format is wrong
    - width cannot be parsed to int
    - data directory is missing
    - fail to create output file
    - data line is longer than spec
extensibility
    - create a map for all data types
    - create a map for all file types
performance
    - read large file line by line
scalability
    - multi-thread to read a lot of files
unit test
    - no spec
    - wrong spec format
    - one spec
    - multiple specs
    - spec with no data
    - spec with 1 data file
    - spec with multiple data files
    - data line too long
    - data line too short
    - cannot parse boolean or int
    - correct data file
    - different data types
'''
