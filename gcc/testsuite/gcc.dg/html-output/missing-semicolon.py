# Verify that basics of HTML output work.
#
# For reference, we expect this textual output:
#
# PATH/missing-semicolon.c: In function ‘missing_semicolon’:
# PATH/missing-semicolon.c:8:12: error: expected ‘;’ before ‘}’ token
#     8 |   return 42 /* { dg-error "expected ';' before '.' token" } */
#       |            ^
#       |            ;
#     9 | }
#       | ~           

from htmltest import *

import pytest

@pytest.fixture(scope='function', autouse=True)
def html_tree():
    return html_tree_from_env()

def test_basics(html_tree):
    root = html_tree.getroot ()
    assert root.tag == make_tag('html')

    head = root.find('xhtml:head', ns)
    assert head is not None

    title = head.find('xhtml:title', ns)
    assert title.text.endswith('gcc/testsuite/gcc.dg/html-output/missing-semicolon.c')

    body = root.find('xhtml:body', ns)
    assert body is not None

    diag_list = body.find('xhtml:div', ns)
    assert diag_list is not None
    assert diag_list.attrib['class'] == 'gcc-diagnostic-list'

    diag = diag_list.find('xhtml:div', ns)
    assert diag is not None
    assert diag.attrib['class'] == 'gcc-diagnostic'

    message = diag.find('xhtml:span', ns)
    assert message is not None
    assert message.attrib['class'] == 'gcc-message'
    assert message.text == "expected '"
    assert message[0].tag == make_tag('span')
    assert message[0].attrib['class'] == 'gcc-quoted-text'
    assert message[0].text == ';'
    assert message[0].tail == "' before '"
    assert message[1].tag == make_tag('span')
    assert message[1].attrib['class'] == 'gcc-quoted-text'
    assert message[1].text == '}'
    assert message[1].tail == "' token"

    pre = diag.find('xhtml:pre', ns)
    assert pre is not None
    assert pre.attrib['class'] == 'gcc-generated-patch'
    assert pre.text.startswith('--- ')
