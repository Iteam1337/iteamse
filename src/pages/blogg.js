import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Blog from '../../lib/js/re/pages/Blog'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'

export default () => {
  const data = useStaticQuery(graphql`
    query allGhostPost {
      allGhostPost {
        nodes {
          authors {
            id
            name
          }
          plaintext
          title
          slug
        }
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <title>Iteam | Blogg</title>
      </Helmet>
      <Blog data={data.allGhostPost.nodes} />
    </Layout>
  )
}
