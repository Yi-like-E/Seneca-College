import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { AboutComponent } from './about/about.component';
import { AlbumComponent } from './album/album.component';
import { ArtistDiscographyComponent } from './artist-discography/artist-discography.component';
import { NewReleasesComponent } from './new-releases/new-releases.component';
import { NotFoundComponent } from './not-found/not-found.component';

const routes: Routes = [
  {path: 'newReleases', component: NewReleasesComponent},
  {path: 'artist', component: ArtistDiscographyComponent},
  {path: 'album', component:AlbumComponent},
  {path: 'about', component:AboutComponent},
  {path: '', redirectTo:'/newReleases', pathMatch:'full'},
  {path: '**', component:NotFoundComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
