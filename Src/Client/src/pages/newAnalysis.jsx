import React, { useState } from 'react';
import Router from 'next/router';
import ButtonToolbar from 'react-bootstrap/ButtonToolbar';
import Button from 'react-bootstrap/Button';

import Page from '../components/page';
import GetData, { SendData } from '../components/getData';
import NewRuleCategoryTable from '../components/newRuleCategoryTable';

const getRuleTables = ruleCategories => {
  const categories = Object.keys(ruleCategories).filter(x => x != '_id');
  return categories.map(name => (
    <NewRuleCategoryTable
      key={name}
      category={name}
      results={ruleCategories[name]}
      descriptions={ruleCategories[name]}
    />
  ));
};

const sendFormData = () => {
  const switches = [...document.getElementsByTagName('input')];
  const enabledRules = switches.filter(s => s.checked === true).map(s => s.id);

  const file = document.getElementById('fileUploader').files[0];
  const filePath = document.getElementById('fileUploader').value;
  const fileName = filePath.slice(filePath.lastIndexOf('\\') + 1);
  const timeRun = new Date().toISOString();
  const runId = `${fileName}:${timeRun}`;

  let formData = new FormData();
  formData.set('rules', enabledRules);
  formData.set('runId', runId);
  formData.set('fileName', fileName);
  formData.set('file', file);
  formData.set('time', timeRun);

  (async () => {
    const response = await SendData('NewAnalysis', formData);

    if (response.status === 200) Router.push(`/previous?runId=${runId}`);
  })();
};

export default function NewAnalysis() {
  const ruleDefinitions = GetData('RuleDefinitions');
  const isDataReady = ruleDefinitions.data.length > 0;
  const ruleCategories = isDataReady ? ruleDefinitions.data[0] : [];

  const [isLoading, setIsLoading] = useState(false);

  return (
    <Page>
      {getRuleTables(ruleCategories)}
      <ButtonToolbar>
        <Button
          variant="outline-dark"
          onClick={() => document.getElementById('fileUploader').click()}
          style={{ margin: '5px 5px 5px 0px' }}
        >
          Add files
        </Button>
      </ButtonToolbar>

      <input
        type="file"
        webkitdirectory
        directory
        multiple
        id="fileUploader"
        style={{ display: 'none' }}
        accept=".cpp"
        multiple
      />

      <ButtonToolbar>
        <Button
          onClick={
            isLoading
              ? null
              : () => {
                  const fileUploader = document.getElementById('fileUploader');

                  if (fileUploader.files.length < 1) {
                    alert('You must select at least 1 file.');
                  } else {
                    setIsLoading(!isLoading);
                    sendFormData();
                  }
                }
          }
          style={{ margin: '5px 5px 5px 0px' }}
        >
          {isLoading ? 'Loading...' : 'Run Analysis'}
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
