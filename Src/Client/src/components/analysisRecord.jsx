import React, { useState, useEffect } from 'react';
import Card from 'react-bootstrap/Card';
import ListGroup from 'react-bootstrap/ListGroup';
import ListGroupItem from 'react-bootstrap/ListGroupItem';
import Link from 'next/link';

const generateURL = (file, date) => `/previous?runId=${file}:${date}`;

const dateItem = (file, date) => (
  <ListGroupItem key={date}>
    <Link href={generateURL(file, date)}>
      <a>{new Date(date).toDateString()}</a>
    </Link>
  </ListGroupItem>
);

export default function AnalysisRecord(props) {
  return (
    <Card
      style={{
        width: '75%',
        marginBottom: '10px',
        fontWeight: 'bold',
        fontStyle: 'italic'
      }}
    >
      <Card.Header>{props.name}</Card.Header>
      <Card.Body>
        <ListGroup variant="flush" style={{ margin: '-20px' }}>
          {props.dates.map(date => dateItem(props.name, date))}
        </ListGroup>
      </Card.Body>
    </Card>
  );
}
