#include "CmdAbstract.h"
#include "CmdAddPointAxis.h"
#include "CmdAddPointGraph.h"
#include "CmdCopy.h"
#include "CmdCut.h"
#include "CmdDelete.h"
#include "CmdEditPointAxis.h"
#include "CmdFactory.h"
#include "CmdMoveBy.h"
#include "CmdPaste.h"
#include "CmdSettingsAxesChecker.h"
#include "CmdSettingsColorFilter.h"
#include "CmdSettingsCoords.h"
#include "CmdSettingsCurveNames.h"
#include "CmdSettingsCurveProperties.h"
#include "CmdSettingsExport.h"
#include "CmdSettingsGridRemoval.h"
#include "CmdSettingsPointMatch.h"
#include "CmdSettingsSegments.h"
#include "Document.h"
#include "DocumentSerialize.h"
#include "EngaugeAssert.h"
#include "MainWindow.h"
#include <QXmlStreamReader>

CmdFactory::CmdFactory ()
{
}

CmdAbstract *CmdFactory::createCmd (MainWindow &mainWindow,
                                    Document &document,
                                    QXmlStreamReader &reader)
{
  CmdAbstract *cmd = 0;

  QXmlStreamAttributes attributes = reader.attributes();
  if (!attributes.hasAttribute(DOCUMENT_SERIALIZE_CMD_TYPE) ||
      !attributes.hasAttribute(DOCUMENT_SERIALIZE_CMD_DESCRIPTION)) {

    // Invalid xml
    ENGAUGE_ASSERT(false);

  }

  // Get common attributes
  QString cmdType = attributes.value(DOCUMENT_SERIALIZE_CMD_TYPE).toString();
  QString cmdDescription = attributes.value(DOCUMENT_SERIALIZE_CMD_DESCRIPTION).toString();

  if (cmdType == DOCUMENT_SERIALIZE_CMD_ADD_POINT_AXIS) {
    cmd = new CmdAddPointAxis (mainWindow,
                               document,
                               cmdDescription,
                               reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_ADD_POINT_GRAPH) {
    cmd = new CmdAddPointGraph (mainWindow,
                                document,
                                cmdDescription,
                                reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_COPY) {
    cmd = new CmdCopy (mainWindow,
                       document,
                       cmdDescription,
                       reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_CUT) {
    cmd = new CmdCut (mainWindow,
                      document,
                      cmdDescription,
                      reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_DELETE) {
    cmd = new CmdDelete (mainWindow,
                         document,
                         cmdDescription,
                         reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_EDIT_POINT_AXIS) {
    cmd = new CmdEditPointAxis (mainWindow,
                                document,
                                cmdDescription,
                                reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_MOVE_BY) {
    cmd = new CmdMoveBy (mainWindow,
                         document,
                         cmdDescription,
                         reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_PASTE) {
    cmd = new CmdPaste (mainWindow,
                        document,
                        cmdDescription,
                        reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_AXES_CHECKER) {
    cmd = new CmdSettingsAxesChecker (mainWindow,
                                      document,
                                      cmdDescription,
                                      reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_COLOR_FILTER) {
    cmd = new CmdSettingsColorFilter (mainWindow,
                                      document,
                                      cmdDescription,
                                      reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_COORDS) {
    cmd = new CmdSettingsCoords (mainWindow,
                                 document,
                                 cmdDescription,
                                 reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_CURVE_NAMES) {
    cmd = new CmdSettingsCurveNames (mainWindow,
                                     document,
                                     cmdDescription,
                                     reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_CURVE_PROPERTIES) {
    cmd = new CmdSettingsCurveProperties (mainWindow,
                                          document,
                                          cmdDescription,
                                          reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_EXPORT) {
    cmd = new CmdSettingsExport (mainWindow,
                                 document,
                                 cmdDescription,
                                 reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_GRID_REMOVAL) {
    cmd = new CmdSettingsGridRemoval (mainWindow,
                                      document,
                                      cmdDescription,
                                      reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_POINT_MATCH) {
    cmd = new CmdSettingsPointMatch (mainWindow,
                                     document,
                                     cmdDescription,
                                     reader);
  } else if (cmdType == DOCUMENT_SERIALIZE_CMD_SETTINGS_SEGMENTS) {
    cmd = new CmdSettingsSegments (mainWindow,
                                   document,
                                   cmdDescription,
                                   reader);
  } else {

    // Invalid xml
    ENGAUGE_ASSERT (false);

  }

  return cmd;
}
