// /1. 亲和数：
const getP = (num) => {
    let sum = 1;
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum;
}

const fr = (n) => {
    const result = [];
    for (let i = 0; i < n; i++) {
        const sum1 = getP(i);
        if (sum1 > i && sum1 < n) {
            const sum2 = getP(sum1);
            if (sum2 === i) {
                result.push([i, sum1]);
            }
        }
    }
    return result;
}

//2. 优化：
const getAll = (n) => {
    const sums = new Array(n).fill(1);
    sums[0] = 0;
    for (let i = 2; i < n; i++) {
        for (let j = i + 1; j < n; j += i) {
            sums[j] += i;
        }
    }
    return sums;
}
console.log(getAll(3000)[220]);

// /3. fp 开发：
const p1 = (x) => x + 1;
const f2 = (f) => (x) => f(f(x))

console.log(p1(0));
console.log(f2(p1)(0));
console.log(
    f2(f2)(p1)(0) // 2^2
);
console.log(
    f2(f2)(f2)(p1)(0) // f16 -> p1(1), 2^4
);
console.log(
    f2(f2)(f2)(f2)(p1)(0) // 2^16
);

f2(p1) // (x) => p1(p1(x))
f2(f2) // (x) => f2(f2)(x)
f2(f2)(p1) // f2(f2(p1))
f2(p1) // (x) => p1(p1(x))
