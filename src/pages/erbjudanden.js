import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import Offers from '../../lib/js/re/pages/Offers'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query Offers {
      contentfulSidaErbjudanden {
        headerText1
        headerTextBgColor
        headerImage {
          file {
            url
          }
          localFile {
            childImageSharp {
              fluid(maxWidth: 1920, quality: 95) {
                ...GatsbyImageSharpFluid
              }
            }
            publicURL
          }
        }
        offersLeadText {
          offersLeadText
        }
        contactTitle
        contactSubtitle
        contacts {
          avatar {
            fluid(maxWidth: 232, quality: 90) {
              src
            }
          }
          email
          location
          name
          phoneNumber
          short
          title
        }
      }
      allContentfulErbjudande(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          offerOrder
          offerTitle
          offerLead {
            offerLead
          }
          offerUspOneTitle
          offerOneUspText {
            offerOneUspText
          }
          offerUspTwoTitle
          offerTwoUspText {
            offerTwoUspText
          }
          offerUspThreeTitle
          offerThreeUspText {
            offerThreeUspText
          }
          offerUspFourTitle
          offerFourUspText {
            offerFourUspText
          }
          offerIntroText {
            offerIntroText
          }
          offerIntroImage {
            file {
              url
            }
          }
          offerIllustrationImage {
            file {
              url
            }
          }
        }
      }
    }
  `)

  React.useEffect(() => {
    if (window.document) {
      const script = document.createElement('script')

      script.id = 'iteamse__hubspotForm'
      script.src = 'https://js.hsforms.net/forms/v2.js'

      document.body.appendChild(script)

      script.addEventListener('load', () => {
        if (window.hbspt) {
          window.hbspt.forms.create({
            portalId: '5211588',
            formId: 'ef02e5ff-fce0-4321-9f9b-715101c7682d',
            target: '#hubspotForm',
          })
        }
      })
    }

    // eslint-disable-next-line
    ;() => {
      if (window.document) {
        document.body.removeChild('#hubspotForm')
        document.body.removeChild('iteamse__hubspotForm')
      }
    }
  }, [])

  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>Iteam | Erbjudanden</title>
        <meta property="og:title" content="Iteam | Erbjudanden" />
        <meta
          property="og:image"
          content={
            data.contentfulSidaErbjudanden.headerImage.localFile.publicURL
          }
        />
      </Helmet>
      <Offers
        data={data.contentfulSidaErbjudanden}
        offers={data.allContentfulErbjudande.nodes}
      />
    </Layout>
  )
}
