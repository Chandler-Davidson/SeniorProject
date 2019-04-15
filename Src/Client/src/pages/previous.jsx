import React from 'react';

import Button from 'react-bootstrap/Button';
import ButtonToolbar from 'react-bootstrap/ButtonToolbar';

// import Parser from 'json2csv';
import { withRouter } from 'next/router';
import Page from '../components/page';
import GetData from '../components/getData';
import RuleCategoryTable from '../components/ruleCategoryTable';
import Converter, { json2csv } from 'json-2-csv';
import downloader from 'downloadjs';

const getRuleTables = (results, descriptions) => {
  const validDescriptions = Object.keys(descriptions).filter(x => x !== '_id');

  let finalComponent = [];

  for (let category in validDescriptions) {
    let appliedRules = [];

    const strCategory = validDescriptions[category];

    for (let result in results) {
      if (descriptions[strCategory].some(x => x.id === result)) {
        appliedRules.push({ [result]: results[result] });
      }
    }

    if (appliedRules.length > 0)
      finalComponent.push(
        <RuleCategoryTable
          key={strCategory}
          category={strCategory}
          results={appliedRules}
          descriptions={descriptions[strCategory]}
        />
      );
  }

  return finalComponent;
};

function Previous(props) {
  const runId = props.router.query.runId;

  const ruleDefinitions = GetData('RuleDefinitions');
  const analysis = GetData(`PreviousRun/${runId}`);
  const fileName = runId.slice(0, runId.indexOf(':'));
  const timeRun = runId.slice(runId.indexOf(':') + 1);

  console.log(analysis);

  const isDataReady =
    analysis.data.length > 0 && ruleDefinitions.data.length > 0;
  const ruleTables = isDataReady
    ? getRuleTables(analysis.data[0].Rules, ruleDefinitions.data[0])
    : [];

  return (
    <Page>
      <h2>{fileName}</h2>
      {ruleTables}
      <ButtonToolbar>
        <Button
          style={{ margin: '5px 5px 5px 0px' }}
          onClick={async () => {
            const data = [
              {
                fileName: fileName,
                timeRun: timeRun,
                ruleOutput: analysis.data[0].Rules
              }
            ];

            const csv = json2csv(data, (err, csv) => {
              downloader(csv, `${fileName}:${timeRun}.csv`);
            });
          }}
        >
          Export
        </Button>
        <Button
          href="/"
          variant="outline-primary"
          style={{ margin: '5px 5px 5px 0px' }}
        >
          Back
        </Button>
      </ButtonToolbar>
    </Page>
  );
}

export default withRouter(Previous);
