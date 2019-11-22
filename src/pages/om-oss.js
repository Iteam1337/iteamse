import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import About from '../../lib/js/re/pages/About'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query AboutUs {
      allContentfulKollegor(filter: { node_locale: { eq: "sv-SE" } }) {
        totalCount
      }
      contentfulSidaOmOss {
        headerTextBgColor
        headerText1
        headerText2
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
        funTitle
        funText {
          funText
        }
        goodText {
          goodText
        }
        goodTitle
        imageBleed {
          fluid(maxWidth: 1920, quality: 95) {
            ...GatsbyContentfulFluid_withWebp
          }
        }
        valueText {
          valueText
        }
        valueTitle
        valueeText
        valueIteam {
          valueIteam
        }
        stabilityTitle
        stabilityText {
          stabilityText
        }
        stabilityIcons {
          description
          file {
            url
          }
        }
        contactTitle
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
          phoneNumber
        }
      }
      illustrationFun: file(relativePath: { eq: "illustration-fun.svg" }) {
        publicURL
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>Iteam | Om oss</title>
      </Helmet>
      <About
        data={data.contentfulSidaOmOss}
        illustrationFun={data.illustrationFun.publicURL}
        numberOfEmployees={data.allContentfulKollegor.totalCount}
      />
    </Layout>
  )
}
