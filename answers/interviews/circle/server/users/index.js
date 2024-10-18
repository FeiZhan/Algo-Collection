import _ from 'lodash';

import Util from '../util';
import nameData from './names';

// Statically generate our list of users.  We pre-generate the list at startup rather than
// generating a new id and name on the fly for each request because we want the ids and
// names to be consistent.  We also only generate a few so that it's possible to get multiple
// payments for the same user after only a small number of requests.

const ID_START = 100;
const USERS_COUNT = 20;

// List of users
const users = [];

// It's extremely unlikely that we'll randomly generate the same name twice, but we check
// to be safe
const selectedNames = {};

while (users.length < USERS_COUNT) {
  const firstName = _.sample(nameData.first);
  const lastName = _.sample(nameData.last);
  const fullName = `${firstName} ${lastName}`;

  // We somehow selected a name that's already been generated, so try again
  if (selectedNames[fullName]) {
    continue;
  }

  const id = ID_START + users.length;
  users.push({
    id,
    name: fullName,
  });
}

// Log the users at startup so that we can see who is available
console.log('The following users are available: ');
console.log(users);

// Return a list of all users.
const getAllUsers = () => {
  return users;
};

// Return a boolean indicating whether an object is a valid user object, by making sure
// that the name and id match up.
const isValidUser = (user) => {
  if (!_.isNumber(user.id)) {
    return false;
  }

  // Fetch the user we expect to see from the sorted list based on the id, and make sure
  // it has the same name as the one passed in.
  const expectedUser = users[user.id - ID_START];
  return expectedUser && (expectedUser.name === user.name);
};

// Get a random pair of users, guaranteed to be different, based on the output of a PRNG.
const pickUsers = (prng) => {
  // Picking the first user is easy
  const user1 = Util.seededSample(prng, users);

  // Make sure we don't pick the same user2 as user 1
  let user2;
  do {
    user2 = Util.seededSample(prng, users);
  } while (user2.id === user1.id);

  return [user1, user2];
};

export default {
  getAllUsers,
  isValidUser,
  pickUsers,
};
