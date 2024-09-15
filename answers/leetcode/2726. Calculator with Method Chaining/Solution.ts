class Calculator {

    private result: number;
    
    constructor(value: number) {
        this.result = value;
    }
    
    add(value: number): Calculator {
        this.result += value;
        return this;
    }
    
    subtract(value: number): Calculator {
        this.result -= value;
        return this;
    }
    
    multiply(value: number): Calculator {
        this.result *= value;
        return this;
    }
    
    divide(value: number): Calculator {
        if (value === 0) {
            throw "Division by zero is not allowed";
        }

        this.result /= value;
        return this;
    }
    
    power(value: number): Calculator {
        this.result = Math.pow(this.result, value);
        return this;
    }
    
    getResult(): number {
        return this.result;
    }
}