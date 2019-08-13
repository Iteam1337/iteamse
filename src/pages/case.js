import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'
import Cases from '../../lib/js/re/pages/Cases'

export default () => {
  const data = useStaticQuery(graphql`
    query Case {
      contentfulSidaCases {
        headerImage {
          title
          file {
            url
          }
        }
        headerText1
        headerText2
        headerTextBgColor
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
      allContentfulProjekt(
        filter: { node_locale: { eq: "sv-SE" } }
        sort: { fields: createdAt }
      ) {
        nodes {
          title
          thumbnailImage {
            file {
              url
            }
          }
          shortDescription
          slug
        }
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <title>Iteam | Case</title>
      </Helmet>
      <Cases
        data={data.contentfulSidaCases}
        projects={data.allContentfulProjekt.nodes}
      />
    </Layout>
  )
}