import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Labs from '../../lib/js/re/pages/Labs'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'

export default () => {
  const data = useStaticQuery(graphql`
    query allGhostPost {
      allGhostPost {
        nodes {
          feature_image
          excerpt
          published_at(formatString: "DD MMMM YYYY", locale: "sv-SE")
          primary_author {
            profile_image
            name
          }
          slug
          title
        }
      }
      ghostSettings {
        cover_image
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <title>Iteam | Labs</title>
      </Helmet>
      <Labs posts={data.allGhostPost.nodes} settings={data.ghostSettings} />
    </Layout>
  )
}
