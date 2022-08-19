import { Component, OnInit } from '@angular/core';
import { AnyCatcher } from 'rxjs/internal/AnyCatcher';
import albumData from '../data/albums.json';
import artistData from '../data/artist.json';

@Component({
  selector: 'app-artist-discography',
  templateUrl: './artist-discography.component.html',
  styleUrls: ['./artist-discography.component.css']
})
export class ArtistDiscographyComponent implements OnInit {

  albums: any;
  artist: any;

  constructor() { }

  ngOnInit(): void {
    this.albums = albumData.items.filter((curValue, index, self) => 
      self.findIndex(t=> t.name.toUpperCase() === curValue.name.toUpperCase()) === index);
    this.artist = artistData;
  }

}
