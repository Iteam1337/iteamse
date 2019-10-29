import React from 'react'
import Layout from '../Layout'
import { graphql } from 'gatsby'
import Opportunity from '../../lib/js/re/pages/Opportunity'

export default ({ data }) => {
  return (
    <Layout>
      <Opportunity data={data.contentfulAnnonser} />
    </Layout>
  )
}

export const query = graphql`
  query Opportunity($urlId: String!) {
    contentfulAnnonser(urlId: { eq: $urlId }) {
      aboutUsTitle
      aboutUs {
        aboutUs
      }
      applicationTitle
      application {
        application
      }
      bonusKnowledgeTitle
      bonusKnowledge {
        bonusKnowledge
      }
      contactTitle
      headerText1
      headerText2
      headerTextBgColor
      headerImage {
        file {
          url
        }
      }
      knowledgeTitle
      knowledge {
        knowledge
      }
      location
      perksTitle
      perks {
        perks
      }
      roleTitle
      role {
        role
        id
      }
      technicalitiesTitle
      technicalities {
        technicalities
      }
      title
      contacts {
        avatar {
          file {
            url
          }
        }
        email
        name
        short
        title
      }
    }
  }
`
