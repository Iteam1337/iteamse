import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import Cases from '../../lib/js/re/pages/Cases'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query Cases {
      contentfulSidaCases {
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
            fixed(width: 450, height: 450) {
              ...GatsbyContentfulFixed_withWebp
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
        <html lang="sv" />
        <title>Iteam | Case</title>
      </Helmet>
      <Cases
        data={data.contentfulSidaCases}
        projects={data.allContentfulProjekt.nodes}
      />
    </Layout>
  )
}
