import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import Index from '../../lib/js/re/pages/Index'
import Layout from '../Layout'

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
            fluid(maxWidth: 232, quality: 90) {
              src
            }
          }
          email
          name
          location
          short
          title
        }
      }
      illustrationIteamI: file(
        relativePath: { eq: "illustration-iteam-i.svg" }
      ) {
        publicURL
      }
      greenBlob: file(relativePath: { eq: "green-blob.svg" }) {
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
        <html lang="sv" />
        <title>Iteam - There's a better way</title>
        <meta property="og:title" content="Iteam - There's a better way" />
        <meta property="og:image" content={data.illustrationIteamI.publicURL} />
        <script src="https://chatbot.sirchat.iteamdev.se/embed/closr.min.js" />
        <script type="text/javascript">
          {`setTimeout(() => {Closr.init({ accountId: "e98e7bd1-9f1b-4a48-aec3-311431008ade" })}, 500)`}
        </script>
      </Helmet>
      <Index
        data={data.contentfulSidaStartsida2019}
        greenBlob={data.greenBlob.publicURL}
        illustrationIteamI={data.illustrationIteamI.publicURL}
        illustrationGroup={data.illustrationGroup.publicURL}
        illustrationCrane={data.illustrationCrane.publicURL}
      />
    </Layout>
  )
}
