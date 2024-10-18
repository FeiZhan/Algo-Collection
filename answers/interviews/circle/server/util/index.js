// Seeded range function.  Given a pre-seeded PRNG, select a float between min and max,
// rounded to the given number of decimals.
const seededRange = (prng, min, max, decimals) => {
  const rand = prng.quick() * (max - min) + min;
  return rand.toFixed(decimals);
};

// Seeded sample function.  Given a pre-seeded PRNG, randomly selects an element
// from the given array.
const seededSample = (prng, arr) => arr[Math.floor(prng.quick() * (arr.length - 1))];

export default {
  seededSample,
  seededRange,
};
