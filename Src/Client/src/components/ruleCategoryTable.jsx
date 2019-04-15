import React from 'react';
import Table from 'react-bootstrap/Table';

import RuleResult from './ruleResult';

export default function RuleCategoryTable(props) {
  const { descriptions } = props;

  return (
    <Table striped bordered hover size="sm">
      <thead>
        <tr>
          <th>{props.category}</th>
          <th>Value</th>
        </tr>
      </thead>
      <tbody>
        {props.results.map((rule, i) => (
          <RuleResult
            key={i}
            id={Object.keys(rule)[0]}
            result={rule[Object.keys(rule)[0]]}
            description={descriptions.find(x => x.id === Object.keys(rule)[0])}
          />
        ))}
      </tbody>
    </Table>
  );
}
