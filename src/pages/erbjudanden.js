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
          }
        }
        offersLeadText {
          offersLeadText
        }
        contactTitle
        contactSubtitle
        contacts {
          avatar {
            file {
              url
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

  return (
    <Layout>
      <Helmet>
        <title>Iteam | Erbjudanden</title>
      </Helmet>
      <Offers
        data={data.contentfulSidaErbjudanden}
        offers={data.allContentfulErbjudande.nodes}
      />
    </Layout>
  )
}
