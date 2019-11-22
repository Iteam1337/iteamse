import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import HowWeWork from '../../lib/js/re/pages/HowWeWork'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query HowWeWork {
      contentfulSidaHurViJobbar {
        headerTextBgColor
        headerText1
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
        methodTitle
        methodText {
          methodText
        }
        sharingText {
          sharingText
        }
        sharingTitle
        teamText {
          teamText
        }
        teamTitle
        customersText {
          customersText
        }
        imageBleed {
          fluid(maxWidth: 1920, quality: 95) {
            ...GatsbyContentfulFluid_withWebp
          }
        }
        customersTitle
        contactTitle
        contacts {
          avatar {
            file {
              url
            }
          }
          email
          location
          name
          short
          title
          phoneNumber
        }
        hiringTitle
        openApplicationText {
          openApplicationText
        }
        openApplicationHeader
      }
      illustrationGroup: file(relativePath: { eq: "illustration-group.svg" }) {
        publicURL
      }
      illustrationShare: file(relativePath: { eq: "illustration-share.svg" }) {
        publicURL
      }
      allContentfulAnnonser(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          title
          location
          urlId
        }
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>Iteam | Metod</title>
      </Helmet>
      <HowWeWork
        ads={data.allContentfulAnnonser.nodes}
        data={data.contentfulSidaHurViJobbar}
        illustrationGroup={data.illustrationGroup.publicURL}
        illustrationShare={data.illustrationShare.publicURL}
      />
    </Layout>
  )
}
