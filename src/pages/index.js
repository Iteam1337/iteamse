import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Index from '../../lib/js/re/pages/Index'
import '../index.css'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query Start {
      contentfulSidaStartsida2019 {
        ctaText {
          ctaText
        }
        ctaTitle
        ctaButtonText
        weAreTitle
        weAreText {
          weAreText
        }
        weOfferText {
          weOfferText
        }
        weOfferTitle
        ourMethodText {
          ourMethodText
        }
        ourMethodTitle
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
      illustrationGroup: file(relativePath: { eq: "illustration-group.svg" }) {
        publicURL
      }
      illustrationCrane: file(relativePath: { eq: "illustration-crane.png" }) {
        publicURL
      }
    }
  `)

  return (
    <Layout>
      <Index
        data={data.contentfulSidaStartsida2019}
        illustrationGroup={data.illustrationGroup.publicURL}
        illustrationCrane={data.illustrationCrane.publicURL}
      />
    </Layout>
  )
}
