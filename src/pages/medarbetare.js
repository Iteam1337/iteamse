import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import Coworkers from '../../lib/js/re/pages/Coworkers'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query Colleagues {
      allContentfulKollegor(
        filter: { node_locale: { eq: "sv-SE" } }
        sort: { order: ASC, fields: name }
      ) {
        nodes {
          avatar {
            fluid(maxWidth: 232, quality: 90) {
              src
            }
          }
          name
          location
          short
          title
          phoneNumber
          email
        }
      }
      contentfulSidaTeamet {
        headerText1
        headerTextBgColor
        headerImage {
          file {
            url
          }
          localFile {
            childImageSharp {
              fluid(maxWidth: 1920, quality: 95) {
                ...GatsbyImageSharpFluid
              }
            }
          }
        }
        contactTitle
        contacts {
          avatar {
            fluid(maxWidth: 232, quality: 90) {
              src
            }
          }
          email
          location
          name
          short
          title
        }
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>Iteam | Medarbetare</title>
      </Helmet>
      <Coworkers
        data={data.contentfulSidaTeamet}
        coworkers={data.allContentfulKollegor.nodes}
      />
    </Layout>
  )
}
