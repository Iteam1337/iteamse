import React from 'react'

export const onRenderBody = ({ setPostBodyComponents }) => {
  setPostBodyComponents([
    <script
      charSet="utf-8"
      type="text/javascript"
      src="//js.hsforms.net/forms/shell.js"
    ></script>,
  ])
}
