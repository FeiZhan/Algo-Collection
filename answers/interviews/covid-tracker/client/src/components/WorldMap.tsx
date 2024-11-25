import React, { useEffect, useState } from 'react';
import { ComposableMap, Geographies, Geography } from 'react-simple-maps';
import { scaleLinear } from 'd3-scale';
import { Tooltip, Typography, CircularProgress } from '@mui/material';
import DataType from '../types/DataType';
import ColumnType from '../types/ColumnType';

const colorScale = scaleLinear<string>()
  .domain([0, 1000000, 10000000])
  .range(["#e0f7fa", "#26c6da", "#01579b"]);

const geoUrl =
  "https://raw.githubusercontent.com/subyfly/topojson/master/world-countries.json";

interface WorldMapProps {
  column: ColumnType;
  endDate: string;
  onCountrySelect: (countryName: string) => void;
}

const WorldMap: React.FC<WorldMapProps> = ({ column, endDate, onCountrySelect }) => {
  const [countryData, setCountryData] = useState<{ [key: string]: number }>({});
  const [tooltipContent, setTooltipContent] = useState<string | null>(null);
  const [mousePosition, setMousePosition] = useState({ x: 0, y: 0 });
  const [loading, setLoading] = useState(false);

  useEffect(() => {
    if (column && endDate) {
      setLoading(true);
      fetch(`http://localhost:5000/api/covid?column=${column}&endDate=${endDate}`)
        .then((response) => {
          if (!response.ok) {
            throw new Error(`Error fetching data: ${response.statusText}`);
          }
          return response.json();
        })
        .then((data: DataType[]) => {
          const dataMap: { [key: string]: number } = {};
          data.forEach((item) => {
            const value = parseInt(item[column]);
            if (!isNaN(value)) {
              dataMap[item.iso_code] = value;
            }
          });
          setCountryData(dataMap);
          setLoading(false);
        })
        .catch((error) => {
          console.error('Failed to fetch data:', error);
          setLoading(false);
        });
    }
  }, [column, endDate]);

  const handleMouseEnter = (
    event: React.MouseEvent<SVGPathElement, MouseEvent>,
    countryData: { iso_code: string; [key: string]: any; location: string }
  ) => {
    setTooltipContent(`Country: ${countryData.location}, ${column}: ${countryData[column]}`);
    setMousePosition({ x: event.clientX, y: event.clientY });
  };

  const handleMouseLeave = () => {
    setTooltipContent(null);
  };

  const handleCountryClick = (countryName: string) => {
    onCountrySelect(countryName);
  };

  const tooltipStyles: React.CSSProperties = {
    position: 'absolute',
    left: mousePosition.x,
    top: mousePosition.y - 10,
    pointerEvents: 'none' as 'none',
    maxWidth: 250,
    backgroundColor: 'rgba(0, 0, 0, 0.7)',
    color: '#fff',
    borderRadius: 4,
    padding: 5,
    fontSize: '12px',
    zIndex: 1000,
  };

  return (
    <div style={{ width: '100%', maxWidth: '1000px', margin: '0 auto' }}>
      {loading ? (
        <div style={{ textAlign: 'center' }}>
          <CircularProgress />
          <p>Loading data...</p>
        </div>
      ) : (
        <ComposableMap projectionConfig={{ scale: 200 }}>
          <Geographies geography={geoUrl}>
            {({ geographies }) =>
              geographies.map((geo) => {
                const isoCode = geo.id;
                const value = countryData[isoCode] || 0;
                return (
                  <Geography
                    key={geo.rsmKey}
                    geography={geo}
                    fill={colorScale(value)}
                    onMouseEnter={(event) =>
                      handleMouseEnter(event, {
                        iso_code: isoCode,
                        [column]: value,
                        location: geo.properties.name,
                      })
                    }
                    onMouseLeave={handleMouseLeave}
                    onClick={() => handleCountryClick(geo.properties.name)}
                    style={{
                      default: { outline: 'none' },
                      hover: { fill: '#FF5722', outline: 'none' },
                      pressed: { fill: '#E42', outline: 'none' },
                    }}
                  />
                );
              })
            }
          </Geographies>
        </ComposableMap>
      )}

      {tooltipContent && (
        <Tooltip
          open
          title={<Typography>{tooltipContent}</Typography>}
          placement="top"
          style={tooltipStyles}
        >
          <div />
        </Tooltip>
      )}
    </div>
  );
};

export default WorldMap;
