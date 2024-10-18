import React, {useCallback, useEffect, useState} from 'react';

import Container from 'react-bootstrap/Container';
import Table from 'react-bootstrap/Table'

import './App.css';

const App = () => {
    const [payments, setPayments] = useState([]);
    const [result, setResult] = useState([]);
    const [text, setText] = useState('');

    const search = useCallback(() => {
      const searchResult = payments.filter((payment) => {
        const searchText = text.toLowerCase();
        const concat = Object.values(payment.data).map((value) => {
          if (typeof value === 'object') {
            return Object.values(value).join(' ');
          } else {
            return value;
          }
        }).join(' ').toLowerCase();
        return concat.includes(searchText);
      });
      setResult(searchResult);
    }, [payments, text]);

    const onInput = useCallback((e) => {
      setText(e.target.value);
      search();
    }, [search]);

    useEffect(() => {
      const interval = setInterval(() => {
      fetch('http://localhost:8080/payments')
      .then((result) => result.json())
      .then((data) => {
        let newPayments = [...payments, data];
        if (newPayments.length > 25) {
          newPayments = newPayments.slice(newPayments.length - 25, newPayments.length);
        }
        setPayments(newPayments);
        search();
      })
      .catch(console.error);
      }, 1000);
      return () => {
        clearInterval(interval);
      };
    }, [payments, search, text]);

    return (
      <Container className="p-3">
        <form action="/" method="get">
          <input
              onInput={onInput}
              placeholder="Search"
              type="text"
              value={text}
          />
          <button type="submit">Search</button>
      </form>
        <Table striped bordered hover>
          <thead>
            <tr>
              <th>#</th>
              <th>Sender</th>
              <th>Receiver</th>
              <th>Amount</th>
              <th>Currency</th>
            </tr>
          </thead>
          <tbody>
            {result.map((payment, index) => {
              return (
                <tr key={`payment${index}`}>
                  <td key="index">{index + 1}</td>
                  <td key="sender">{payment.data.sender.name}</td>
                  <td key="receiver">{payment.data.receiver.name}</td>
                  <td key="amount">{payment.data.amount}</td>
                  <td key="currency">{payment.data.currency}</td>
                </tr>
                );
            })}
          </tbody>
        </Table>
      </Container>
    );
}

export default App;
