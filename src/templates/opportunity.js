import React from 'react'
import Layout from '../Layout'
import { graphql } from 'gatsby'
import Opportunity from '../../lib/js/re/pages/Opportunity'

export default ({ data }) => {
  return (
    <Layout>
      <html lang="sv" />
      <title>{`Iteam | Karriär - ${data.contentfulAnnonser.applicationTitle}`}</title>
      <meta
        property="og:title"
        content={`Iteam | Karriär - ${data.contentfulAnnonser.applicationTitle}`}
      />
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
          fluid(maxWidth: 232, quality: 90) {
            src
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
