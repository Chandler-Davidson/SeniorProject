import React, { useState } from 'react';
import Button from 'react-bootstrap/Button';
import Collapse from 'react-bootstrap/Collapse';
import Switch from 'react-switch';

export default function NewRuleResult(props) {
  const { name, description } = props.description;
  const { id, value } = props.result;

  const [isExpanded, setIsExpanded] = useState(false);
  const [isEnabled, setIsEnabled] = useState(false);

  const button = (
    <Switch
      id={id}
      onChange={() => setIsEnabled(!isEnabled)}
      checked={isEnabled}
    />
  );

  return (
    <tr>
      <td
        onClick={() => setIsExpanded(!isExpanded)}
        aria-controls="collapsible"
        aria-expanded={isExpanded}
        style={{ width: '100%' }}
      >
        <Button variant="link">{name}</Button>
        <Collapse in={isExpanded}>
          <div id="collapsible" style={{ margin: '5px' }}>
            {description}
          </div>
        </Collapse>
      </td>
      <td>{value == null ? button : value}</td>
    </tr>
  );
}
