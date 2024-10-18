package com.sailpoint;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.InputMismatchException;

public final class Atm {
    private boolean isLogin = false;
    private boolean isRunning = true;
    private double balance = 0.0;
    private String pin = Constants.DEFAULT_PIN;

    public static void main(String[] args) {
        Atm atm = new Atm();
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            while (atm.isRunning) {
                String input = reader.readLine();
                String output = atm.run(input);
                System.out.println(output);
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    public String run(String input) {
        String result = Constants.OK;
        String[] split = input.split(" ");

        try {
            if (split.length > 0) {
                switch (split[0]) {
                    case Commands.LOGIN:
                        login(split);
                        break;
                    case Commands.VIEW:
                        result = view();
                        break;
                    case Commands.DEPOSIT:
                        deposit(split);
                        break;
                    case Commands.WITHDRAW:
                        withdraw(split);
                        break;
                    case Commands.EXIT:
                        isRunning = false;
                        break;
                    default:
                        throw new RuntimeException(ErrorMessages.UNKNOWN);
                }
            }
        } catch (RuntimeException e) {
            return e.getMessage();
        }

        return result;
    }

    private void login(String[] split) {
        isLogin = false;

        if (split == null) {
            throw new NullPointerException(ErrorMessages.INVALID);
        } else if (split.length < 2) {
            throw new InputMismatchException(ErrorMessages.NO_PIN);
        } else if (split[1].length() != pin.length()) {
            throw new InputMismatchException(ErrorMessages.WRONG_PIN_LENGTH);
        } else if (!split[1].equals(pin)) {
            throw new RuntimeException(ErrorMessages.WRONG_PIN);
        } else {
            isLogin = true;
        }
    }

    private String view() {
        if (!isLogin) {
            throw new RuntimeException(ErrorMessages.UNAUTHORIZED);
        }

        return Double. toString(balance);
    }

    private void deposit(String[] split) {
        if (!isLogin) {
            throw new RuntimeException(ErrorMessages.UNAUTHORIZED);
        }

        balance += parse(split, Double.MAX_VALUE);
    }

    private void withdraw(String[] split) {
        if (!isLogin) {
            throw new RuntimeException(ErrorMessages.UNAUTHORIZED);
        }

        balance -= parse(split, balance);
    }

    private double parse(String[] split, double max) {
        if (split == null) {
            throw new NullPointerException(ErrorMessages.INVALID);
        } else if (split.length < 2) {
            throw new InputMismatchException(ErrorMessages.NO_NUMBER);
        }

        double number = Double.parseDouble(split[1]);
        if (number <= 0) {
            throw new NumberFormatException(ErrorMessages.NOT_POSITIVE);
        } else if (number >= max) {
            throw new NumberFormatException(ErrorMessages.EXCEED_BALANCE);
        }

        return number;
    }
}
