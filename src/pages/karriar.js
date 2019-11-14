import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Layout from '../Layout'
import Career from '../../lib/js/re/pages/Career'
import '../index.css'
import { Helmet } from 'react-helmet'

export default () => {
  const data = useStaticQuery(graphql`
    query Career {
      contentfulSidaJobbaHosOss {
        headerImage {
          title
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
        headerText1
        headerTextBgColor
        contactTitle
        openApplicationLabel
        openApplicationText {
          openApplicationText
        }
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
      allContentfulAnnonser(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          id
          location
          title
          role {
            role
          }
          urlId
        }
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <title>Iteam | Karriär</title>
      </Helmet>
      <Career data={data} />
    </Layout>
  )
}
