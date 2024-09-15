function countStudents(students: number[], sandwiches: number[]): number {
    let count = 0;
    let result = 0;
    while (students.length > 0 && count < students.length) {
        const student = students.shift();
        if (student == sandwiches[0]) {
            result++;
            sandwiches.shift();
            count = 0;
        } else {
            students.push(student);
            count++;
        }
    }

    return students.length;
};