import React from 'react';
import Table from 'react-bootstrap/Table';

import NewRuleResult from './newRuleResult';

export default function NewRuleCategoryTable(props) {
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
          <NewRuleResult
            key={rule.id}
            result={rule}
            description={descriptions.find(x => x.id === rule.id)}
          />
        ))}
      </tbody>
    </Table>
  );
}
