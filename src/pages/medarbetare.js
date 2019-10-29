import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Coworkers from '../../lib/js/re/pages/Coworkers'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'

export default () => {
  const data = useStaticQuery(graphql`
    query Colleagues {
      allContentfulKollegor(
        filter: { node_locale: { eq: "sv-SE" } }
        sort: { order: ASC, fields: name }
      ) {
        nodes {
          avatar {
            file {
              url
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
              fluid(maxWidth: 1920) {
                ...GatsbyImageSharpFluid
              }
            }
          }
        }
        contactTitle
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
  `)

  return (
    <Layout>
      <Helmet>
        <title>Iteam | Medarbetare</title>
      </Helmet>
      <Coworkers
        data={data.contentfulSidaTeamet}
        coworkers={data.allContentfulKollegor.nodes}
      />
    </Layout>
  )
}
