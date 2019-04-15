import React, { useState, useEffect } from 'react';
import ButtonToolbar from 'react-bootstrap/ButtonToolbar';
import Button from 'react-bootstrap/Button';
import Page from '../components/page';
import GetData from '../components/getData';
import AnalysisRecord from '../components/analysisRecord';

const getFileRecords = props =>
  props.map(x => <AnalysisRecord key={x.Name} name={x.Name} dates={x.Dates} />);

export default function Home() {
  const history = GetData('PreviousRun');

  return (
    <Page>
      <div>{getFileRecords(history.data)}</div>

      <ButtonToolbar>
        <Button href="/newAnalysis">New Run</Button>
      </ButtonToolbar>
    </Page>
  );
}
