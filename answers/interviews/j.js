class RangeList {
    #ranges = [];

    add(range) {
        const left = this.#binarySearch(range[0]);
        let right = this.#binarySearch(range[1]);
        if (right === -1) {
            right = left;
        }

        if (left === -1) {
            this.#ranges.push(range);
        } else {
            range[0] = Math.min(range[0], this.#ranges[left][0]);
            range[1] = Math.max(range[1], this.#ranges[right][1]);
            this.#ranges.splice(left, right - left + 1, range);
        }
    }

    remove(range) {
        let left = this.#binarySearch(range[0]);
        let right = this.#binarySearch(range[1]);
        if (right === -1) {
            right = left;
        }

        if (left === -1) {
            return;
        } else if (left === right) {
            if (range[1] < this.#ranges[left][1]) {
                this.#ranges.splice(left + 1, 0, [range[1], this.#ranges[left][1]]);
            }
            if (this.#ranges[left][0] < range[0]) {
                this.#ranges.splice(left + 1, 0, [this.#ranges[left][0], range[0]]);
            }
            this.#ranges.splice(left, 1);
        } else {
            if (this.#ranges[left][0] < range[0]) {
                this.#ranges[left][1] = range[0];
                left++;
            }
            if (range[1] < this.#ranges[right][1]) {
                this.#ranges[right][0] = range[1];
                right--;
            }
            this.#ranges.splice(left, right - left + 1);
        }
    }

    print() {
        const result = this.#ranges
            .map((range) => '[' + range[0] + ', ' + range[1] + ')')
            .reduce((total, value) => total + ' ' + value);
        console.log(result);
    }

    #binarySearch(target) {
        if (this.#ranges.length === 0) {
            return -1;
        }

        let left = 0;
        let right = this.#ranges.length - 1;

        while (left <= right) {
            const middle = Math.floor((left + right) / 2);
            const middleRange = this.#ranges[middle];

            if (middleRange[0] <= target && target <= middleRange[1]) {
                return middle;
            } else if (middleRange[1] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return -1;
    }
}

const rl = new RangeList();
rl.add([1, 5]);
rl.print();
console.log('Expected: [1, 5)');

rl.add([10, 20]);
rl.print();
console.log('Expected: [1, 5) [10, 20)');

rl.add([20, 20]);
rl.print();
console.log('Expected: [1, 5) [10, 20)');

rl.add([20, 21]);
rl.print();
console.log('Expected: [1, 5) [10, 21)');

rl.add([2, 4]);
rl.print();
console.log('Expected: [1, 5) [10, 21)');

rl.add([3, 8]);
rl.print();
console.log('Expected: [1, 8) [10, 21)');

rl.remove([10, 10]);
rl.print();
console.log('Expected: [1, 8) [10, 21)');

rl.remove([10, 11]);
rl.print();
console.log('Expected: [1, 8) [11, 21)');

rl.remove([15, 17]);
rl.print();
console.log('Expected: [1, 8) [11, 15) [17, 21)');

rl.remove([3, 19]);
rl.print();
console.log('Expected: [1, 3) [19, 21)');
