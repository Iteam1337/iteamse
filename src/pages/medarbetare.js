import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
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
            file {
              url
            }
          }
          name
          short
          title
          phoneNumber
          email
        }
      }
      contentfulSidaTeamet {
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
      <Coworkers
        data={data.contentfulSidaTeamet}
        coworkers={data.allContentfulKollegor.nodes}
      />
    </Layout>
  )
}
