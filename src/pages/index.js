import React from 'react'
import { StaticQuery, graphql, useStaticQuery } from 'gatsby'
import Index from '../../lib/js/re/pages/Index'

export default () => {
  const data = useStaticQuery(graphql`
    query Start {
      contentfulSidaStartsida2019 {
        weAreText {
          weAreText
        }
        weAreTitle
      }
    }
  `)

  return <Index data={data.contentfulSidaStartsida2019} />
}
