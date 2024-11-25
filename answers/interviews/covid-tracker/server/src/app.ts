import express from 'express';
import cors from 'cors';
import covidRoutes from './routes/covidRoutes';

const app = express();

app.use(cors());
app.use(express.json());

app.use('/api', covidRoutes);

app.use((err: any, req: express.Request, res: express.Response, next: express.NextFunction) => {
  console.error(err.stack);
  res.status(500).json({ message: 'Internal server error' });
});

app.use((req, res) => {
  res.status(404).json({ message: 'Route not found' });
});

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
