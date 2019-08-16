import React from 'react'
import Layout from '../Layout'
import { graphql } from 'gatsby'
import Coworker from '../../lib/js/re/pages/Coworker'

export default ({ data }) => {
  return (
    <Layout>
      <Coworker data={data.contentfulKollegor} />
    </Layout>
  )
}

export const query = graphql`
  query Coworker($short: String!) {
    contentfulKollegor(short: { eq: $short }) {
      name
      why {
        why
      }
      whyTitle
      title
      phoneNumber
      email
      competenceTitle
      competence {
        competence
      }
      backgroundTitle
      background {
        background
      }
      headerTextBgColor
      headerImage {
        file {
          url
        }
      }
    }
  }
`
