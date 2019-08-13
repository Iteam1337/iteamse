import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
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
          file {
            url
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
      <HowWeWork
        ads={data.allContentfulAnnonser.nodes}
        data={data.contentfulSidaHurViJobbar}
        illustrationGroup={data.illustrationGroup.publicURL}
        illustrationShare={data.illustrationShare.publicURL}
      />
    </Layout>
  )
}
