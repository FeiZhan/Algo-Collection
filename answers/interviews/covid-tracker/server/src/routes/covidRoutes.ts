import express, { Request, Response, NextFunction } from 'express';
import { getCovidData, initializeCovidController } from '../controllers/covidController';

const router = express.Router();

let isDataLoaded = false;

const ensureDataLoaded = async (req: Request, res: Response, next: NextFunction) => {
  if (!isDataLoaded) {
    try {
      await initializeCovidController();
      isDataLoaded = true;
      next();
    } catch (error) {
      console.error('Failed to load COVID data:', error);
      res.status(500).json({ message: 'Failed to load COVID data. Please try again later.' });
    }
  } else {
    next();
  }
};

router.get('/covid', ensureDataLoaded, getCovidData);

export default router;
