interface DataItem {
    iso_code: string;
    continent: string;
    location: string;
    date: string;
    total_cases: string;
    new_cases: string;
    new_cases_smoothed: string;
    total_deaths: string;
    new_deaths: string;
    new_deaths_smoothed: string;
    [key: string]: string;
}

export default DataItem;
