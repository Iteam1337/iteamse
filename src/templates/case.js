import React from 'react'
import Layout from '../Layout'
import { graphql } from 'gatsby'
import Coworker from '../../lib/js/re/pages/Coworker'

export default ({ data }) => {
  return <Layout>{data.contentfulProjekt.title}</Layout>
}

export const query = graphql`
  query Case($slug: String!) {
    contentfulProjekt(slug: { eq: $slug }) {
      title
    }
  }
`
