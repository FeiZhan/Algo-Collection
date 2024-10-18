package com.sailpoint;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.BeforeEach;

class AppTest {
    private Atm atm = null;

    @BeforeEach
    public void beforeEach() {
        atm = new Atm();
    }

    @Test
    public void testApp() {
        assertNotNull(atm);
    }

    @Test
    public void testLoginSuccess() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);
    }

    @Test
    public void testLoginEmpty() {
        String output = atm.run(Commands.LOGIN + " ");
        assertEquals(ErrorMessages.NO_PIN, output);
    }

    @Test
    public void testLoginFailure() {
        String output = atm.run(Commands.LOGIN + " 1235");
        assertEquals(ErrorMessages.WRONG_PIN, output);
    }

    @Test
    public void testViewSuccess() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.VIEW);
        assertEquals("0.0", output);
    }

    @Test
    public void testViewFailure() {
        String output = atm.run(Commands.VIEW);
        assertEquals(ErrorMessages.UNAUTHORIZED, output);
    }

    @Test
    public void testDepositSuccess() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        double money = 123.4;
        output = atm.run(Commands.DEPOSIT + " " + money);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.VIEW);
        assertEquals(Double.toString(money), output);
    }

    @Test
    public void testDepositUnauthorized() {
        double money = 123.4;
        String output = atm.run(Commands.DEPOSIT + " " + money);
        assertEquals(ErrorMessages.UNAUTHORIZED, output);
    }

    @Test
    public void testDepositEmpty() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.DEPOSIT + " ");
        assertEquals(ErrorMessages.NO_NUMBER, output);
    }

    @Test
    public void testDepositNegative() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        double money = -123.4;
        output = atm.run(Commands.DEPOSIT + " " + money);
        assertEquals(ErrorMessages.NOT_POSITIVE, output);
    }

    @Test
    public void testWithdrawSuccess() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        double money = 123.4;
        output = atm.run(Commands.DEPOSIT + " " + money);
        assertEquals(Constants.OK, output);

        double withdraw = 10.2;
        output = atm.run(Commands.WITHDRAW + " " + withdraw);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.VIEW);
        assertEquals(Double.toString(money - withdraw), output);
    }

    @Test
    public void testWithdrawUnauthorized() {
        double money = 123.4;
        String output = atm.run(Commands.WITHDRAW + " " + money);
        assertEquals(ErrorMessages.UNAUTHORIZED, output);
    }

    @Test
    public void testWithdrawEmpty() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.WITHDRAW + " ");
        assertEquals(ErrorMessages.NO_NUMBER, output);
    }

    @Test
    public void testWithdrawNegative() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        double money = 123.4;
        output = atm.run(Commands.DEPOSIT + " " + money);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.WITHDRAW + " -1");
        assertEquals(ErrorMessages.NOT_POSITIVE, output);
    }

    @Test
    public void testWithdrawExceed() {
        String output = atm.run(Commands.LOGIN + " " + Constants.DEFAULT_PIN);
        assertEquals(Constants.OK, output);

        double money = 123.4;
        output = atm.run(Commands.DEPOSIT + " " + money);
        assertEquals(Constants.OK, output);

        output = atm.run(Commands.WITHDRAW + " " + (money + 1));
        assertEquals(ErrorMessages.EXCEED_BALANCE, output);
    }

    @Test
    public void testUnknownCommand() {
        String output = atm.run("a");
        assertEquals(ErrorMessages.UNKNOWN, output);
    }
}
