import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Index from '../../lib/js/re/pages/Index'
import '../index.css'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'

export default () => {
  const data = useStaticQuery(graphql`
    query Start {
      contentfulSidaStartsida2019 {
        headerText1
        headerLead {
          headerLead
        }
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
      illustrationIteamI: file(
        relativePath: { eq: "illustration-iteam-i.svg" }
      ) {
        publicURL
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
      <Helmet>
        <title>Iteam - There's a better way</title>
      </Helmet>
      <Index
        data={data.contentfulSidaStartsida2019}
        illustrationIteamI={data.illustrationIteamI.publicURL}
        illustrationGroup={data.illustrationGroup.publicURL}
        illustrationCrane={data.illustrationCrane.publicURL}
      />
    </Layout>
  )
}
