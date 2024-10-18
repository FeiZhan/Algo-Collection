import _ from 'lodash';
import BodyParser from 'body-parser';
import Cors from 'cors';
import Express from 'express';
import Seedrandom from 'seedrandom';

import Config from './config';
import Users from './users';
import Util from './util';

const CURRENCIES = ['BTC', 'GBP', 'EUR', 'JPY', 'USD'];
const DRINKS = ['coffee', 'orange juice', 'soda', 'tea', 'water'];
const FOODS = ['hamburgers', 'hot dogs', 'pasta', 'pizza', 'salad'];

// Build a basic express app
const app = Express();
const { port } = Config.server;

// Keep a list of payment ids that have been used.  This is not thread-safe, but for
// this example that's fine.
const paymentIds = {};

// Parse JSON bodies of requests
app.use(BodyParser.json());

// Add CORS headers to allow everything; this is obviously unsafe in the real world but
// for this example it's fine.
app.use(Cors());

// Endpoint to get randomly generated payments
app.get('/payments', (req, res) => {
  // Seed a PRNG to use to generate all of our random data.  We seed it from the seconds
  // since the epoch, so that if multiple requests are made within the same clock second,
  // they'll get the same data.  Once we have this PRNG, it's very important that all random
  // data be generated from it.  We then regenerate our date object to be based on seconds
  // so that it stays consistent amongst requests within the same second.
  const nowMS = new Date();
  const epochSeconds = Math.round(nowMS.getTime() / 1000);
  const prng = new Seedrandom(epochSeconds);
  const now = new Date(epochSeconds * 1000);

  // Build our random data
  const users = Users.pickUsers(prng);
  const food = Util.seededSample(prng, FOODS);
  const drink = Util.seededSample(prng, DRINKS);

  // See README.md for the response format.
  res.json({
    data: {
      id: Math.round(prng.quick() * 1e16).toString(),
      date: now.toISOString(),
      sender: users[0],
      receiver: users[1],
      amount: Util.seededRange(prng, 0, 1e4, 2).toString(),
      currency: Util.seededSample(prng, CURRENCIES),
      memo: `${food} and ${drink}`,
    },
  });
});

// Endpoint to create a new payment
app.post('/payments', (req, res) => {
  // We don't actually need to store this payment.  We just check if it's correctly formatted, and then randomly choose
  // whether to return success or failure.  We do not necessarily keep the same behavior within the same second; it's
  // all random.

  // Make sure it's correctly formatted; we just do simple type validation.
  const payment = req.body;
  if (!_.isString(payment.id)) {
    return res.status(400).json({ error: 'Incorrectly formatted id' });
  }

  if (paymentIds[payment.id]) {
    console.log(`You retried the same payment id '${payment.id}'`);
    return res.status(409).send({ error: 'That payment id has already been used!' });
  }

  if (!Date.parse(payment.date)) {
    return res.status(400).send({ error: 'Incorrectly formatted date' });
  }

  if (!Users.isValidUser(payment.sender)) {
    return res.status(400).send({ error: 'Incorrectly formatted sender' });
  }

  if (!Users.isValidUser(payment.receiver)) {
    return res.status(400).send({ error: 'Incorrectly formatted receiver' });
  }

  if (payment.sender.id === payment.receiver.id) {
    return res.status(400).send({ error: 'The sender and receiver must be different' });
  }

  if (!_.isString(payment.amount) || !_.isNumber(parseFloat(payment.amount))) {
    return res.status(400).send({ error: 'Incorrectly formatted amount' });
  }

  if (!CURRENCIES.includes(payment.currency)) {
    return res.status(400).send({ error: 'Incorrect formatted currency' });
  }

  // Don't bother doing any validation on the memo

  // Randomly decide if the payment succeeds or fails.
  if (Math.random() < 0.5) {
    console.log(`Payment with id '${payment.id}' failed!  Please try again later.`);
    return res.status(503).send();
  } else {
    // Record that the payment id has been used.
    paymentIds[payment.id] = true;
    console.log(`Payment succeeded: ${JSON.stringify(payment)}`);
    return res.status(201).send();
  }
});

// Endpoint to return a list of all users
app.get('/users', (req, res) => {
  res.json({
    data: Users.getAllUsers(),
  });
});


// Start it listening.  This is the top level so we can't use await.
app.listen(port, () => console.log(`Payments data app listening on port ${port}!`));
