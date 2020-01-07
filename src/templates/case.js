import React from 'react'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'
import { graphql } from 'gatsby'
import Case from '../../lib/js/re/pages/Case'

export default ({ data }) => {
  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>{`Iteam | Case - ${data.contentfulProjekt.title}`}</title>
        <meta
          property="og:title"
          content={`Iteam | Case - ${data.contentfulProjekt.title}`}
        />
        <meta
          property="og:image"
          content={data.contentfulProjekt.logo.localFile.publicURL}
        />
      </Helmet>
      <Case data={{ ...data.contentfulProjekt, ...data.contentfulSidaCases }} />
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
          publicURL
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
      quoteEmployeePosition
      quoteBgColor
    }

    contentfulSidaCases {
      contactTitle
      contactSubtitle
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
