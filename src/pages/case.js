import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Layout from '../Layout'
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
    }
  `)

  return (
    <Layout>
      <Cases data={data.contentfulSidaCases} />
    </Layout>
  )
}

