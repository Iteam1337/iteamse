import React from 'react'
import Layout from '../Layout'
import { graphql } from 'gatsby'
import Case from '../../lib/js/re/pages/Case'

export default ({ data }) => {
  return (
    <Layout>
      <Case data={data.contentfulProjekt} />
    </Layout>
  )
}

export const query = graphql`
  query Case($slug: String!) {
    contentfulProjekt(slug: { eq: $slug }) {
      casePageBackgroundImage {
        file {
          url
        }
        localFile {
          childImageSharp {
            fluid(maxWidth: 1920, quality: 95) {
              src
            }
          }
        }
      }
      casePageImage {
        file {
          url
        }
        localFile {
          childImageSharp {
            fluid(maxWidth: 1920) {
              src
            }
          }
        }
      }
      logo {
        localFile {
          publicURL
        }
      }
      headerBgColor
      slug
      frameworks
      frameworksTitle
      tags
      title
      introductionTitle
      introduction {
        introduction
      }
      processTitle
      process {
        process
      }
      shortDescription
      development {
        development
      }
      developmentTitle
      aboutCompany {
        aboutCompany
      }
      aboutCompanyTitle
      partners {
        partners
      }
      partnersTitle
      contact {
        contact
      }
      contactTitle
      quote {
        quote
      }
      quotePerson
      quoteBgColor
    }
  }
`
