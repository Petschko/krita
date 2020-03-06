/*
 *  Copyright (c) 2009 Cyrille Berger <cberger@cberger.net>
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef _PRESETDOCKER_DOCK_H_
#define _PRESETDOCKER_DOCK_H_

#include <QPointer>
#include <QDockWidget>
#include <KoCanvasObserverBase.h>
#include <kis_canvas2.h>

class KisPaintOpPresetsChooserPopup;

class PresetDockerDock : public QDockWidget, public KoCanvasObserverBase {
    Q_OBJECT
public:
    PresetDockerDock( );
    QString observerName() override { return "PresetDockerDock"; }
    void setCanvas(KoCanvasBase *canvas) override;
    void unsetCanvas() override { m_canvas = 0; setEnabled(false);}
public Q_SLOTS:
    void canvasResourceChanged(int key = 0, const QVariant& v = QVariant());
private:
    QPointer<KisCanvas2> m_canvas;
    KisPaintOpPresetsChooserPopup* m_presetChooser;
};


#endif
